{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  d,u,v,z,x,y,n,i,j,ans: longint;
  ds,xt,yt: array [0..33] of longint;
  dist: array [0..33,0..33] of longint;
  pr,f: array [0..17000010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(x,y,n);
  for i:=1 to n do read(xt[i],yt[i]);
  ans:=0;
  for i:=1 to n do
  begin
    ds[i]:=sqr(x-xt[i])+sqr(y-yt[i]);
    ans:=ans+ds[i];
  end;
  for i:=1 to n do
    for j:=1 to n do dist[i,j]:=sqr(xt[j]-xt[i])+sqr(yt[j]-yt[i]);
  fillchar(f,sizeof(f),100);
  f[0]:=0;
  for i:=0 to 1 shl n-2 do
    if f[i] < 1e9 then
    begin
      u:=0;
      for j:=1 to n do
        if i and (1 shl (j-1)) = 0 then
        begin
          u:=j;
          break;
        end;
      z:=i or (1 shl (u-1));
      v:=f[i]+ds[u];
      if v < f[z] then
      begin
        f[z]:=v;
        pr[z]:=i;
      end;
      for j:=u+1 to n do
        if i and (1 shl (j-1)) = 0 then
        begin
          v:=f[i]+dist[u,j];
          if v < f[z or (1 shl (j-1))] then
          begin
            f[z or (1 shl (j-1))]:=v;
            pr[z or (1 shl (j-1))]:=i;
          end;
        end;
    end;
  writeln(ans+f[1 shl n-1]);
  write('0');
  z:=1 shl n-1;
  while z > 0 do
  begin
    i:=pr[z];
    u:=0;
    for j:=1 to n do
      if i and (1 shl (j-1)) = 0 then
      begin
        u:=j;
        break;
      end;
    d:=i or (1 shl (u-1));
    if d = z then write(' ',u,' 0') else
      for j:=u+1 to n do
        if (i and (1 shl (j-1)) = 0) and (z and (1 shl (j-1)) <> 0) then
        begin
          write(' ',u,' ',j,' 0');
          break;
        end;
    z:=i;
  end;
  writeln;
  close(input);
  close(output);
end.