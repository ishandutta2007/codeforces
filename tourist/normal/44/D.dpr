{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  ans: extended;
  dist: array [0..5010] of extended;
  x,y,z: array [0..5010] of longint;
  n,i,j: longint;
  d: extended;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(x[i],y[i],z[i]);
  for i:=1 to n do dist[i]:=sqrt(sqr(x[i]-x[1])+sqr(y[i]-y[1])+sqr(z[i]-z[1]));
  ans:=1e9;
  for i:=2 to n-1 do
    for j:=i+1 to n do
    begin
      d:=dist[i]+dist[j]+sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]));
      if d < ans then ans:=d;
    end;
  writeln(ans/2:0:17);
  close(input);
  close(output);
end.