var
  st:array[0..500500]of char;
  s:ansistring;
  kst,i:longint;

begin
  readln(s);
  kst:=0;
  for i:=1 to length(s)do
    if (kst>0)and(st[kst]=s[i])
      then dec(kst)
      else begin
        inc(kst);
        st[kst]:=s[i];
      end;
  for i:=1 to kst do write(st[i]);
  writeln;
end.