{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,i,ss,ff,dd,p,q: longint;
  x,y,z,a,b: array [0..10010] of longint;
  c: array [0..10010] of boolean;
begin
{  assign(input,'in'); reset(input);
  assign(output,'out'); rewrite(output);}
  read(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),False);
  for i:=1 to m do
  begin
    read(ss,ff,dd);
    a[ss]:=ff;
    b[ss]:=dd;
    c[ff]:=True;
  end;
  m:=0;
  for i:=1 to n do
    if (a[i] > 0) and not c[i] then
    begin
      p:=i; q:=maxlongint;
      while a[p] > 0 do
      begin
        if b[p] < q then q:=b[p];
        p:=a[p];
      end;
      inc(m);
      x[m]:=i;
      y[m]:=p;
      z[m]:=q;
    end;
  writeln(m);
  for i:=1 to m do writeln(x[i],' ',y[i],' ',z[i]);
  close(input);
  close(output);
end.