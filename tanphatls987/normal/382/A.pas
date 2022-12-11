var a,b:ansistring;
    i,l,r,l1,r1:longint;
begin
readln(a);
readln(b);
l:=0;
while (a[l+1]<>'|') do inc(l);
r:=length(a)-l-1;
l1:=r-l+length(b);
r1:=-r+l+length(b);
if ((l1<0)or(r1<0)or(l1 mod 2=1) or (r1 mod 2=1)) then writeln('Impossible')
else begin
        for i:=l1 div 2 downto 1 do a:=b[i]+a;
        for i:=l1 div 2+1 to length(b) do a:=a+b[i];
        writeln(a);
        end;
end.