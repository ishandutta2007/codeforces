var s:string;
    m,i,ans,cur:longint;
    p,q,h:array[0..300005] of int64;
begin
read(s);
read(m);
p[0]:=1;
for i:=1 to length(s) do p[i]:=p[i-1]*10 mod m;
q[0]:=0;
for i:=1 to length(s) do q[i]:=(q[i-1]*10+ord(s[i])-48) mod m;
h[length(s)+1]:=0;
for i:=length(s) downto 1 do h[i]:=(h[i+1]+(ord(s[i])-48)*p[length(s)-i]) mod m;
ans:=m;
for i:=1 to length(s) do if(ord(s[i])<>48) then
begin
 cur:=(h[i]*p[i-1]+q[i-1]) mod m;
 if cur<ans then ans:=cur;
end;
writeln(ans);
end.