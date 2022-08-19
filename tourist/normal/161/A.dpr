{$R-,S-,Q-,I-,O+}
{$M 30000000}
var
  xa,ya,a,b,na,nb: array [0..200010] of longint;
  ka,n,m,i,j,x,y: longint;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=b[l+random(r-l+1)];
  repeat
    while b[i] < x do inc(i);
    while x < b[j] do dec(j);
    if i <= j then
    begin
      tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
      tmp:=nb[i]; nb[i]:=nb[j]; nb[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randomize;
  read(n,m,x,y);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do nb[i]:=i;
  Sort(1,n);
  for i:=1 to n do
  begin
    a[i]:=b[i];
    na[i]:=nb[i];
  end;
  for i:=1 to m do read(b[i]);
  for i:=1 to m do nb[i]:=i;
  Sort(1,m);
  ka:=0; j:=1;
  for i:=1 to m do
  begin
    while (j <= n) and (a[j]+y < b[i]) do inc(j);
    if (j <= n) and (a[j]-x <= b[i]) and (b[i] <= a[j]+y) then
    begin
      inc(ka);
      xa[ka]:=na[j];
      ya[ka]:=nb[i];
      inc(j);
    end;
  end;
  writeln(ka);
  for i:=1 to ka do writeln(xa[i],' ',ya[i]);
end.