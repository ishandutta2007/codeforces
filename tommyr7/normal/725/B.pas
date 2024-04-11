const time:array[1..6] of longint=(3,4,5,2,1,0);
var n,ans,i:int64;
    s:string;
	x:char;
begin
  readln(s);
  i:=1;
  while (i<=length(s)) and (ord(s[i])>=48) and (ord(s[i])<=57) do
  begin
    n:=n*10+ord(s[i])-48;
    inc(i);
  end;
  x:=s[length(s)];
  if (n mod 4=1) or (n mod 4=3) then ans:=int64(2*((n-1) div 4))+1 else ans:=int64(2*((n-1) div 4))+2;
  dec(ans);
  ans:=int64(ans*6);
  if (n mod 4=1) or (n mod 4=2) then ans:=ans+n-1 else ans:=ans+n-3;
  ans:=ans+time[ord(x)-96]+1;
  writeln(ans);
end.