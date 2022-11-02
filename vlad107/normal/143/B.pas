var
  p,s:ansistring;
  st,x,i:longint;

begin
  readln(s);
  if (pos('.',s)=0)then s:=s+'.';
  x:=pos('.',s);
  if (x+2<length(s))then delete(s,x+3,length(s));
  while (x+2>length(s))do s:=s+'0';
  if (s[1]='-')then st:=2 else st:=1;
  if (s[1]='-')then begin
    delete(s,1,1);
    s:='('+s+')';
  end;
  p:='';
  for i:=1 to length(s)do 
    if (i<=st)then p:=p+s[i] else
    if (i>=x)then p:=p+s[i] else 
    if ((x-i)mod 3=0)then p:=p+','+s[i] else
    p:=p+s[i];
  if (p[1]='(')then insert('$',p,2)else insert('$',p,1);    
  writeln(p);  
end.