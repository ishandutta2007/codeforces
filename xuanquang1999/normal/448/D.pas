uses math;
var n, m, k, l, r, mid, res, x: int64;

function CountLess(x: int64): int64;
var ans: int64;
    i: longint;
begin
 ans:=0;
 for i:=1 to n do
  ans:=ans+min((x-1) div i, m);
 exit(ans);
end;

begin
 readln(n, m, k);

 l:=1; r:=m*n; res:=0;
 while l <= r do
  begin
   mid:=(l+r) div 2;
   x:=CountLess(mid);
   if x < k then 
    begin
     if mid > res then res:=mid;
     l:=mid+1;
    end
   else r:=mid-1;
  end;

 writeln(res);
end.