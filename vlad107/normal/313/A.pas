var
  ans,i,x:longint;
  s,p:ansistring;

begin
  readln(s);
  val(s,ans);
  for i:=length(s)-1 to length(s)do 
    if (s[i]<>'-')then begin
      p:=s;
      delete(p,i,1);
      val(p,x);
      if (x>ans)then ans:=x;
    end;
  writeln(ans);
end.