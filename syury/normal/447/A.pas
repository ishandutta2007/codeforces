var h,i,n,p,x,c:longint;
    t:array[0..305]of boolean;

begin
fillchar(t,sizeof(t),false);
readln(p,n);
c:=-1;
for i:=1 to n do
begin
   readln(x);
   h:=x mod p;
   if (t[h]=true)and(c=-1) then c:=i
   else t[h]:=true;
end;
write(c);
end.