
var
  s:ansistring;
  n,j,k4,k7,i:longint;
  procedure outw(x:longint);
    begin
      for i:=1 to x div 2 do write('4');
      for i:=1 to x div 2 do write('7');
      writeln;
      halt(0);
    end;
begin
  readln(s);
  n:=length(s);
  if (length(s)and 1=1)then outw(n+1);
  k4:=0;k7:=0;
  i:=1;
  while (i<=length(s))do begin
    if (s[i]<>'4')and(s[i]<>'7')then begin
      if (s[i]<'7')then break;
      dec(i);
      while (i>0)and(s[i]='7')do dec(i);
      if (i=0)then outw(n+2);
      break;
    end;
    if (s[i]='4')then inc(k4) else inc(k7);
    if (k4>n div 2)then break;
    if (k7>n div 2)then begin
      while (i>0)and(s[i]='7')do dec(i);
      if (i=0)then outw(n+2);
      break;
    end;
    inc(i);
  end;
  if (i>length(s))then begin
    writeln(s);
    exit;
  end;
  k4:=0;k7:=0;
  j:=1;
  while (j<i)do begin
    if (s[j]='4')then inc(k4)else inc(k7);
    inc(j);
  end;
  if (s[i]<'4')and(k4<n div 2)then s[i]:='4'else begin
    if (k7=n div 2)then begin
      dec(i);
      while (i>0)and(s[i]='4')do dec(i);
      while (i>0)and(s[i]='7')do dec(i);
      if (i=0)then outw(n+2);
    end;
    s[i]:='7';
  end;
  j:=1;
  k4:=0;k7:=0;
  while (j<=i)do begin
    if (s[j]='4')then inc(k4)else inc(k7);
    write(s[j]);
    inc(j);
  end;
  for i:=1 to (n div 2)-k4 do write('4');
  for i:=1 to (n div 2)-k7 do write('7');
  writeln;
end.