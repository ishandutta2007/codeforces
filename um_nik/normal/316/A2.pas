var s:string;
t,n,i,k,m:integer;
ans:int64;
a:array [1..10] of integer;

begin
readln(s);
n:=length(s);
m:=0;
k:=0;
for i:=1 to 10 do a[i]:=0;
ans:=1;
if s[1]='?' then ans:=9 else
  begin
  if (ord(s[1])>64) and (ord(s[1])<75) then
    begin
    a[ord(s[1])-64]:=1;
    k+=1;
    ans:=9;
    t:=1;
    end;
  end;
for i:=2 to n do
  begin
  if s[i]='?' then m+=1 else
    begin
    if (ord(s[i])>64) and (ord(s[i])<75) and (a[ord(s[i])-64]=0) then
      begin
      a[ord(s[i])-64]:=1;
      k+=1;
      end;
    end;
  end;
for i:=t+1 to k do ans*=11-i;
write(ans);
for i:=1 to m do write(0);
end.