var
  s:ansistring;
  k,i,n,tt,rr,q,j:longint;
  a:array[0..11111]of longint;
  was:array[0..11111]of boolean;
begin
  readln(k);
  readln(s);
  n:=length(s);
  for i:=1 to n do
    if (s[i]='?')then a[i]:=0
    else a[i]:=ord(s[i])-96;
  for i:=1 to n shr 1 do
    if (a[i]=0)and(a[n-i+1]<>0)then a[i]:=a[n-i+1]else
    if (a[i]<>0)and(a[n-i+1]=0)then a[n-i+1]:=a[i]else
    if (a[i]<>0)and(a[n-i+1]<>0)and(a[i]<>a[n-i+1])then begin
      writeln('IMPOSSIBLE');
      exit;
    end;
  for i:=1 to (n+1) shr 1 do begin
    if (a[i]<>0)then continue;
    for j:=1 to k do begin
      a[i]:=j;
      for q:=1 to k do was[q]:=false;
      tt:=0;rr:=0;
      for q:=1 to (n+1) shr 1 do
        if (a[q]=0)
          then inc(rr)
          else was[a[q]]:=true;
      for q:=1 to k do
        if (was[q])then inc(tt);
      if (rr+tt<k)then begin
        a[i]:=0;
        continue;
      end;
      break;
    end;
    if (a[i]=0)then begin
      writeln('IMPOSSIBLE');
      exit;
    end else a[n-i+1]:=a[i];
  end;
  for i:=1 to k do was[i]:=false;
  for i:=1 to n do was[a[i]]:=true;
  tt:=0;
  for i:=1 to k do 
    if (not was[i])then begin
      writeln('IMPOSSIBLE');
      exit;
    end;
  for i:=1 to n do write(chr(a[i]+96));
end.