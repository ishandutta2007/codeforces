{$r-,q-,s-,i-,o+}
var
  s:ansistring;
  n,m,nm,i,j,x,tmp:longint;
  p,nom:array[0..500500]of longint;
  f:array[0..777,0..777]of int64;
  cr,k:int64;

  function calc(i,q:longint):int64;
    begin
      if (i>nm)then begin
        calc:=ord(q=0);
        exit;
      end;
      if (f[i][q]=-1)then begin
        if (s[i]='?')then begin
          f[i][q]:=calc(i+1,q+1);
          if (q>0)then f[i][q]:=f[i][q]+calc(i+1,q-1);
        end else
        if (s[i]='(')then f[i][q]:=calc(i+1,q+1)else
        if (q>0)then f[i][q]:=calc(i+1,q-1) else
        f[i][q]:=0;
      end;
      if (f[i][q]>k)then f[i][q]:=k+1;
      calc:=f[i][q];
    end;

begin
  read(n,m,k);
  nm:=n+m-1;
  for i:=1 to nm do p[i]:=10000000;
  for i:=1 to n do
    for j:=1 to m do begin
      read(x);
      if (x<p[j+i-1])then p[j+i-1]:=x;
    end;
  for i:=1 to nm do nom[i]:=i;
  for i:=1 to nm-1 do
    for j:=1 to nm-1 do
      if (p[j]>p[j+1])then begin
        tmp:=p[j];p[j]:=p[j+1];p[j+1]:=tmp;
        tmp:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp;
      end;
  s:='';
  for i:=1 to nm do s:=s+'?';
  for i:=1 to nm do begin
    s[nom[i]]:='(';
    fillchar(f,sizeof(f),$ff);
    cr:=calc(1,0);
    if (cr>=k)then continue;
    s[nom[i]]:=')';
    k:=k-cr;
  end;
  for i:=1 to n do begin
    for j:=1 to m do write(s[j+i-1]);
    writeln;
  end;
end.