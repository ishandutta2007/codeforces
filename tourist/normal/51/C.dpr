{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  a: array [0..200010] of longint;
  x: array [0..200010] of int64;
  ll,rr,xx,r: int64;
  n,i,c: longint;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=a[l+random(r-l+1)];
  repeat
    while a[i] < x do inc(i);
    while x < a[j] do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  Sort(1,n);
  for i:=1 to n do a[i]:=a[i]*2;
  ll:=0; rr:=round(1e9);
  while ll < rr do
  begin
    xx:=(ll+rr) shr 1;
    r:=0; c:=0;
    for i:=1 to n do
      if a[i] > r then
      begin
        inc(c);
        x[c]:=a[i]+xx;
        r:=a[i]+2*xx;
      end;
    if c <= 3 then rr:=xx
    else ll:=xx+1;
  end;
  writeln(0.5*ll:0:6);
  xx:=ll;
  r:=0; c:=0;
  for i:=1 to n do
    if a[i] > r then
    begin
      inc(c);
      x[c]:=a[i]+xx;
      r:=a[i]+2*xx;
    end;
  if c < 3 then
    for i:=c+1 to 3 do x[i]:=x[c];
  writeln(0.5*x[1]:0:6,' ',0.5*x[2]:0:6,' ',0.5*x[3]:0:6);
  close(input);
  close(output);
end.