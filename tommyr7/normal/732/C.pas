uses math;
var a,b,c,ans,maxx:int64;
begin
  readln(a,b,c);
  maxx:=max(a,b);
  maxx:=max(maxx,c);
  ans:=0;
  if (maxx-a>1) then ans:=ans+maxx-a-1;
  if (maxx-b>1) then ans:=ans+maxx-b-1;
  if (maxx-c>1) then ans:=ans+maxx-c-1;
  writeln(ans);
end.