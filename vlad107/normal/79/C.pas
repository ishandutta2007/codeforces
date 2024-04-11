var
  q,pos,len,n,i,j,f:longint;
  s:ansistring;
  t:array[0..15]of ansistring;
begin
  readln(s);
  readln(n);
  for i:=1 to n do readln(t[i]);
  f:=length(s)+1;
  len:=-1;
  for i:=length(s) downto 1 do begin
    for j:=1 to n do begin
      if (i+length(t[j])-1>length(s))then continue;
      q:=1;
      while (q<=length(t[j]))and(t[j][q]=s[i+q-1])do inc(q);
      if (q>length(t[j]))and(i+q-2<f)then f:=i+q-2;
    end;
    if (f-i>len)then begin
      len:=f-i;
      pos:=i;
    end;
  end;
  writeln(len,' ',pos-1);
end.