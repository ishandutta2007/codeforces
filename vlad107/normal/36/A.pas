var             
  n,i,j,per:longint;
  s:ansistring;
begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(n);
  readln(s);
  per:=0;
  j:=0;
  for i:=1 to n do begin
    if (s[i]='0')then continue;
    if (j=0)then begin
      j:=i;
      continue;
    end;
    if (per=0)then begin
      per:=i-j;
      j:=i;
      continue;
    end;
    if (i-j<>per)then begin
      writeln('NO');
      exit;
    end;
    j:=i;
  end;
  writeln('YES');
end.