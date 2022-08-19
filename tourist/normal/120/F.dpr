{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  tt,qq,n,i,j,x,y,k,cur,ans: longint;
  g: array [0..111,0..111] of longint;
begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  read(tt);
  ans:=0;
  for qq:=1 to tt do
  begin
    read(n);
    for i:=1 to n do
      for j:=1 to n do
        if i = j then g[i,j]:=0
        else g[i,j]:=round(1e9);
    for i:=1 to n-1 do
    begin
      read(x,y);
      if g[x,y] > 1 then
      begin
        g[x,y]:=1;
        g[y,x]:=1;
      end;
    end;
    for k:=1 to n do
      for i:=1 to n do
        for j:=1 to n do
          if g[i,k]+g[k,j] < g[i,j] then g[i,j]:=g[i,k]+g[k,j];
    cur:=0;
    for i:=1 to n do
      for j:=1 to n do
        if g[i,j] > cur then cur:=g[i,j];
    inc(ans,cur);
  end;
  writeln(ans);
  close(input);
  close(output);
end.