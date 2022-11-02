var
  px,o,n,x,y,i,m:longint;
  s:ansistring;

begin
  readln(n,x,y);
  readln(s);
  if (s[4]='h')then o:=1 else o:=2;
  readln(s);
  m:=length(s);
  for i:=1 to m-1 do begin
    if (s[i]='0')then begin
      px:=x;
      if (x=1)then inc(x)else
      if (x=n)then dec(x)else
      if (abs(x-1-y)>abs(x+1-y))then dec(x)else
      inc(x);
      if (x=y)then x:=px;
      if (y=1)and(o=1)then o:=2;
      if (y=n)and(o=2)then o:=1;
      if (o=1)then dec(y)else inc(y);
      if (x=y)and(x=px)then begin writeln('Controller ',i);exit;end else
      if (x=y)then x:=px;
    end else begin
      if (y=1)and(o=1)then o:=2;
      if (y=n)and(o=2)then o:=1;
      if (o=1)then dec(y)else inc(y);
      if (y=n)then x:=1 else
      if (y=1)then x:=n else
      if (o=1)then x:=n else
      x:=1;
      if (x=y)then begin writeln('Controller ',i);exit;end;
    end;
  end;
  writeln('Stowaway');
end.