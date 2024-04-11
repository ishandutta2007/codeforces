var
  n,i:longint;
  found:boolean;
  r:array[0..1111]of longint;
  s:ansistring;

begin
  randomize;
  readln(n);
  readln(s);
  for i:=1 to n do r[i]:=1;
  found:=true;
  while (found)do begin
    found:=false;
    for i:=1 to n-1 do begin
      if (r[i]>=r[i+1])and(s[i]='R')then begin
        inc(r[i+1]);found:=true;
      end;
      if (r[i]<=r[i+1])and(s[i]='L')then begin
        inc(r[i]);found:=true;
      end;
      if (r[i]<>r[i+1])and(s[i]='=')then begin
        if (r[i]<r[i+1])then inc(r[i])else inc(r[i+1]);
        found:=true;
      end;
    end;
  end;
  for i:=1 to n do write(r[i],' ');
  writeln;
end.