{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i: longint;
  minx,miny,maxx,maxy,ans,m1,m2,m3,m4: int64;
  x,y: array [0..100010] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  minx:=x[1]; maxx:=x[1];
  miny:=y[1]; maxy:=y[1];
  for i:=2 to n do
  begin
    if x[i] < minx then minx:=x[i];
    if y[i] < miny then miny:=y[i];
    if x[i] > maxx then maxx:=x[i];
    if y[i] > maxy then maxy:=y[i];
  end;
  dec(minx); dec(miny);
  inc(maxx); inc(maxy);
  ans:=((maxx-minx)+(maxy-miny))*2;
  m1:=x[1]+y[1]; m2:=x[1]+y[1];
  m3:=x[1]-y[1]; m4:=x[1]-y[1];
  for i:=2 to n do
  begin
    if x[i]+y[i] < m1 then m1:=x[i]+y[i];
    if x[i]+y[i] > m2 then m2:=x[i]+y[i];
    if x[i]-y[i] < m3 then m3:=x[i]-y[i];
    if x[i]-y[i] > m4 then m4:=x[i]-y[i];
  end;
  dec(m1); inc(m2);
  dec(m3); inc(m4);
  ans:=ans-(m1-(minx+miny));
  ans:=ans-((maxx+maxy)-m2);
  ans:=ans-(m3-(minx-maxy));
  ans:=ans-((maxx-miny)-m4);
  writeln(ans);
  close(input);
  close(output);
end.