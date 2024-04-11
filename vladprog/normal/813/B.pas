{$macro+}
{$define free}

{$ifdef free}
uses math;
{$endif}

const
  inf=2000000000000000000;

var
  i,j:longint;
  x,y,l,r,n,m:int64;
  a:array[1..4000]of int64;
  powx,powy:array[0..60]of int64;

procedure sort(l,r: longint);
var
  i,j: longint;
  x,y: int64;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
   while a[i]<x do
    inc(i);
   while x<a[j] do
    dec(j);
   if not(i>j) then
     begin
        y:=a[i];
        a[i]:=a[j];
        a[j]:=y;
        inc(i);
        j:=j-1;
     end;
  until i>j;
  if l<j then
   sort(l,j);
  if i<r then
   sort(i,r);
end;

begin
  read(x,y,l,r);
  powx[0]:=1;
  for i:=1 to 60 do
    if r div x >= powx[i-1]
      then powx[i]:=powx[i-1]*x
      else powx[i]:=inf;
  {for i:=1 to 60 do
    write(powx[i],' ');
  writeln;}
  powy[0]:=1;
  for i:=1 to 60 do
    if r div y >= powy[i-1]
      then powy[i]:=powy[i-1]*y
      else powy[i]:=inf;
  {for i:=1 to 60 do
    write(powy[i],' ');
  writeln;}
  n:=2;
  a[1]:=l-1;
  a[2]:=r+1;
  for i:=0 to 60 do
    begin
      if powx[i]>r then break;
      for j:=0 to 60 do
        begin
          if powx[i]+powy[j]<l then continue;
          if powx[i]+powy[j]>r then break;
          inc(n);
          a[n]:=powx[i]+powy[j]
        end;
    end;
  sort(1,n);
  {for i:=1 to n do
    write(a[i],' ');
  writeln;}
  m:=0;
  for i:=1 to n-1 do
  begin
    //if m<a[i+1]-a[i]-1 then writeln(a[i],' ',a[i+1]);
    m:=max(m,a[i+1]-a[i]-1);
  end;
  writeln(m)
end.