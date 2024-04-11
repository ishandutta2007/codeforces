var
  n,i,j:longint;
  s:ansistring;
  a:array[0..500500]of ansistring;
  power:array[0..500500]of boolean;

begin
  n:=0;
  while (not eof(input))do begin
    readln(s);
    inc(n);
    a[n]:=s;
  end;
  for i:=1 to n do begin
    s:=a[i];
    j:=1;
    while (j<=length(s))and(s[j]=' ')do inc(j);
    if (j<=length(s))and(s[j]='#')then power[i]:=true else power[i]:=false;
  end;
  power[n+1]:=true;
  for i:=1 to n do begin
    if (not power[i])then begin
      s:='';
      for j:=1 to length(a[i])do 
        if (a[i][j]<>' ')then s:=s+a[i][j];
      a[i]:=s;
    end;
    write(a[i]);
    if (power[i])or(power[i+1])then writeln;
  end;
end.