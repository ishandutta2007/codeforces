const
  m=1000000007;

var
  n,s:int64;
  i,j:longint;
  a,pow:array[0..300000]of int64;

function power(k:int64):int64;
var
  p:int64;
begin
  if pow[k]=0 then
    begin
      p:=power(k div 2);
      pow[k]:=(p*p*power(k mod 2)) mod m
    end;
  power:=pow[k]
end;

    procedure sort(l,r: longint);
      var
         i,j,x,y: int64;
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
  fillchar(pow,sizeof(pow),0);
  pow[0]:=1;
  pow[1]:=2;
  read(n);
  for i:=1 to n do
    read(a[i]);
  sort(1,n);
  dec(n);
  s:=0;
  for i:=1 to n do
    s:=(s+((((a[i+1]-a[i]) mod m)*(power(n-i+1)-1) mod m)*(power(i)-1) mod m)) mod m;
  writeln(s)
end.