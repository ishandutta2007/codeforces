{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  k,a,b,n,i,j,p,t,q: longint;
  s: ansistring;
  can: array [0..1010,0..1010] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(k,a,b);
  readln(s);
  n:=length(s);
  fillchar(can,sizeof(can),False);
  can[0,0]:=True;
  for i:=1 to n do
    for j:=1 to k do
      for p:=a to b do
        if p > i then break else
        if can[i-p,j-1] then can[i,j]:=True;
  if not can[n,k] then writeln('No solution') else
  begin
    i:=n; j:=k; t:=0;
    while i > 0 do
      for p:=a to b do
        if can[i-p,j-1] then
        begin
          for q:=1 to p do
          begin
            inc(t);
            write(s[t]);
          end;
          writeln;
          dec(i,p);
          dec(j);
          break;
        end;
  end;
  close(input);
  close(output);
end.