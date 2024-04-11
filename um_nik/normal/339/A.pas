var n,i,j:integer;
a:array [1..3] of integer;
s:string;
begin
readln(s);
n:=length(s);
a[1]:=0;
a[2]:=0;
a[3]:=0;
for i:=1 to n do
  begin
  if i mod 2=0 then continue;
  a[ord(s[i])-48]+=1;
  end;
s:='';
for i:=1 to 3 do
  begin
  for j:=1 to a[i] do s+=chr(48+i)+'+';
  end;
writeln(copy(s,1,n));
end.