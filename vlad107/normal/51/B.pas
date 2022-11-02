var
  st,res:array[1..10000] of longint;
  x,s:ansistring;
  ks,n,m,i,j:longint;

begin
  s:='';
  while (not eof(input)) do begin
    readln(x);
    s:=s+x;
  end;
  i:=1;
  m:=0;
  n:=0;
  fillchar(res,sizeof(res),$0);
  ks:=0;
  while (i<=length(s)) do begin
    if (s[i]='<')and(s[i+1]='t')and(s[i+2]='a')then begin
      inc(m);
      if (m>n)then n:=m;
      inc(ks);
      st[ks]:=m;
      inc(i,7);
      continue;
    end;
    if (s[i]='<')and(s[i+1]='/')and(s[i+2]='t')and(s[i+3]='a')then begin
      dec(ks);
      inc(i,8);
      continue;
    end;
    if (s[i]+s[i+1]+s[i+2]='<tr')then begin
      inc(i,4);
      continue;
    end;
    if (s[i]+s[i+1]+s[i+2]='</t')then begin
      inc(i,5);
      continue;
    end;
    if (s[i]+s[i+1]+s[i+2]='<td')then begin
      inc(res[st[ks]]);
      inc(i,4);
      continue;
    end;
  end;
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (res[j]>res[j+1])then begin
        m:=res[j];
        res[j]:=res[j+1];
        res[j+1]:=m;
      end;
  for i:=1 to n do write(res[i], ' ');
end.