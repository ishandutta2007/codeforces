{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  n,l,v1,v2,i,ke,b: longint;
  z: extended;
  ans,e: array [-400010..400010] of extended;
  pe,a: array [-400010..400010] of longint;

procedure Sort(l,r:longint);
var
  i,j,tt: longint;
  x,tmp: extended;
begin
  i:=l; j:=r;
  x:=e[l+random(r-l+1)];
  repeat
    while e[i] < x do inc(i);
    while x < e[j] do dec(j);
    if i <= j then
    begin
      tmp:=e[i]; e[i]:=e[j]; e[j]:=tmp;
      tt:=pe[i]; pe[i]:=pe[j]; pe[j]:=tt;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randomize;
  read(n,l,v1,v2);
  for i:=1 to n do read(a[i]);
  z:=l*(v2/(v1+v2));
  ke:=0;
  for i:=1 to n do
    if a[i] >= z then
    begin
      inc(ke); e[ke]:=a[i]-z; pe[ke]:=1;
      inc(ke); e[ke]:=a[i]; pe[ke]:=-1;
    end else
    begin
      inc(ke); e[ke]:=a[i]-z+2*l; pe[ke]:=1;
      inc(ke); e[ke]:=2*l; pe[ke]:=-1;
      inc(ke); e[ke]:=0; pe[ke]:=1;
      inc(ke); e[ke]:=a[i]; pe[ke]:=-1;
    end;
  inc(ke); e[ke]:=0; pe[ke]:=0;
  inc(ke); e[ke]:=2*l; pe[ke]:=0;
  Sort(1,ke);
  for i:=0 to n do ans[i]:=0;
  b:=0;
  for i:=1 to ke-1 do
  begin
    b:=b+pe[i];
    ans[b]:=ans[b]+(e[i+1]-e[i]);
  end;
  for i:=0 to n do writeln(ans[i]/(2*l):0:17);
end.