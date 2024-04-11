var
  j,i,ans,x,y,z:longint;
  p,s:ansistring;

begin
  readln(s);
  ans:=-1;
  for i:=1 to length(s)-2 do 
    for j:=i+1 to length(s)-1 do begin
      if (i>7)then continue;
      if (j-i>7)then continue;
      if (length(s)-j>7)then continue;
      if (s[1]='0')and(i>1)then continue;
      if (s[i+1]='0')and(j>i+1)then continue;
      if (s[j+1]='0')and(j+1<length(s))then continue;
      p:=s;
      val(copy(p,1,i),x);
      delete(p,1,i);
      val(copy(p,1,j-i),y);
      delete(p,1,j-i);
      val(p,z);
      if (x>1000000)then continue;
      if (y>1000000)then continue;
      if (z>1000000)then continue;
      if (x+y+z>ans)then ans:=x+y+z;
    end;
  writeln(ans);
end.