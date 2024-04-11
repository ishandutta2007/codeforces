{$mode delphi}

var s:string;
    w:array[1..26]of longint;
    m,j,k:longint;

function n(x:string):longint;
var i:longint;
begin
result:=0;
for i:=1 to length(s) do
   inc(result,w[byte(s[i])-96]*i);
end;

function sum(l,r:longint):longint;
var i:longint;
begin
result:=0;
for i:=l to r do
   inc(result,i);
end;

begin
readln(s);
readln(k);
m:=0;
for j:=1 to 26 do
begin
   read(w[j]);
   if w[j]>m then m:=w[j];
end;
write(n(s)+sum(length(s)+1,length(s)+k)*m);
end.