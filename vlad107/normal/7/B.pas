var
  x,n,m,i,j,kol,tt:longint;
  ch:char;
  s:string;
  found:boolean;
  a:array[0..100000]of longint;
begin
  readln(tt,n);
  m:=0;
  fillchar(a,sizeof(a),$0);
  while (tt>0)do begin
    dec(tt);
    s:='';
    read(ch);
    while (ch in['a'..'z'])do begin
      s:=s+ch;read(ch);
    end;
    if (s[1]='d')then begin
      for i:=n downto 1 do
        if (a[i]=0)then
          for j:=i to n do
            a[j]:=a[j+1];
      if (tt>0)then readln;
      continue;
    end;
    readln(x);
    if (s[1]='a')then begin
      kol:=0;
      found:=false;
      if (x>0)then
        for i:=1 to n do begin
          inc(kol,ord(a[i]=0));
          if (i>x)then dec(kol,ord(a[i-x]=0));
          if (kol=x)then begin
            inc(m);
            writeln(m);
            found:=true;
            for j:=i-x+1 to i do a[j]:=m;
            break;
          end;
        end;
      if (not found)then writeln('NULL');
    end else begin
      found:=false;
      if (x>0)then
        for i:=1 to n do
          if (a[i]=x)then begin
            a[i]:=0;
            found:=true;
          end;
      if (not found)then writeln('ILLEGAL_ERASE_ARGUMENT');
    end;
  end;
end.