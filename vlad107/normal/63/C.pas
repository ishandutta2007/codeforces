var
  kt,x,n,i,j,q,t,bb,cc:longint;
  r,a:array[0..1000]of string;
  b,c:array[0..1000]of longint;
  was:array[0..1000]of boolean;
  s:string;
  ok:boolean;
begin
  read(n);
  for i:=1 to n do begin
    read(x,b[i],c[i]);
    str(x,a[i]);
    while (length(a[i])<4)do a[i]:='0'+a[i];
  end;
  kt:=0;
  for i:=0 to 9999 do begin
    str(i,s);
    while (length(s)<4)do s:='0'+s;
    if (s[1]=s[2])or(s[1]=s[3])or(s[1]=s[4])or(s[2]=s[3])or(s[2]=s[4])or(s[3]=s[4])then continue;
    ok:=true;
    for j:=1 to n do begin
      bb:=b[j];cc:=c[j];
      for q:=1 to 4 do
        if (s[q]=a[j][q])then dec(bb);
      for q:=1 to 4 do was[q]:=false;
      for q:=1 to 4 do
        for t:=1 to 4 do
          if (s[t]<>a[j][t])and(not was[q])and(s[q]=a[j][t])then begin
            dec(cc);break;
          end;
      if (bb<>0)or(cc<>0)then begin
        ok:=false;
        break;
      end;
    end;
    if (ok)then begin
      inc(kt);
      r[kt]:=s;
    end;
  end;
  if (kt=0)then writeln('Incorrect data')else
  if (kt=1)then writeln(r[1])else
  writeln('Need more data');
end.