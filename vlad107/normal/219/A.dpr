var
  j,i,n,ls,lt:longint;
  ch:char;
  kol:array['a'..'z']of longint;
  a:array[0..500500]of char;
  s:ansistring;

begin
  readln(n);
  readln(s);
  ls:=length(s);
  if (ls mod n<>0)then begin
    writeln(-1);
    exit;
  end;
  fillchar(kol,sizeof(kol),$0);
  for i:=1 to ls do inc(kol[s[i]]);
  lt:=ls div n;
  for i:=1 to lt do begin
    for ch:='a' to 'z' do 
      if (kol[ch]<>0)then begin
        if (kol[ch]<n)then begin
          writeln(-1);
          exit;
        end;
        for j:=0 to n-1 do a[j*lt+i]:=ch;
        dec(kol[ch],n);
        break;
      end;
  end;
  for i:=1 to ls do write(a[i]);
  writeln;
end.