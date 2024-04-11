var
  sa,sb,sc:array[0..500500]of longint;
  ka,kb,kc,a,b,c,i:longint;

begin
  read(a,c);
  ka:=0;
  kc:=0;
  while (a>0)do begin
    inc(ka);
    sa[ka]:=a mod 3;
    a:=a div 3;
  end;
  while (c>0)do begin    
    inc(kc);
    sc[kc]:=c mod 3;
    c:=c div 3;
  end;
  if (ka>kc)then kb:=ka else kb:=kc;
  for i:=1 to kb do sb[i]:=(sc[i]-sa[i]+27)mod 3;
  b:=0;
  for i:=kb downto 1 do b:=b*3+sb[i];
  writeln(b);
end.