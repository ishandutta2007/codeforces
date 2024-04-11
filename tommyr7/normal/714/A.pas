uses math;
var l1,l2,r1,r2,k,ans,min1,max1:int64;
begin
  readln(l1,r1,l2,r2,k);
  min1:=max(l1,l2);
  max1:=min(r1,r2);
  if (max1>=min1) then ans:=max1-min1+1 else ans:=0;
  if (max1>=k) and (k>=min1) then dec(ans);
  writeln(ans);
end.