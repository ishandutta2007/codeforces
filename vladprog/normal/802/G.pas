{$macro+}
{ $define free}

{$ifdef free}
uses math;
{$endif}

{$ifndef free}
type ansistring=string;
{$endif}

const
  p='heidi';

var
  n,i,j:longint;
  s:ansistring;
  a:array[0..1000,0..5]of longint;

begin
  readln(s);
  n:=length(s);
{$ifdef free}
  fillchar(a,sizeof(a),0);
{$endif}
  for i:=1 to n do
    a[i,0]:=1;
  for i:=1 to n do
    for j:=1 to 5 do
      if s[i]=p[j]
        then a[i,j]:=a[i-1,j]+a[i-1,j-1]
        else a[i,j]:=a[i-1,j];
  if a[n,5]>=1
    then writeln('YES')
    else writeln('NO')
end.