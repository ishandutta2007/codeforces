var
  q,ca,cb,cr,c,res,a,b,bb:longint;

begin
  read(a,b);
  bb:=2;
  ca:=a;cb:=b;
  while (a>0) do begin
    if (a mod 10 + 1 > bb)then bb:=(a mod 10) + 1;
    a:=a div 10;
  end;
  while (b>0) do begin
    if (b mod 10 + 1>bb)then bb:=(b mod 10) + 1;
    b:=b div 10;
  end;
  q:=1;
  while (ca>0) do begin
    a:=(ca mod 10)*q+a;
    ca:=ca div 10;
    q:=q*bb;
  end;
  q:=1;
  while (cb>0) do begin
    b:=q*(cb mod 10)+b;
    cb:=cb div 10;
    q:=q*bb;
  end;
  c:=a+b;
  res:=0;
  cr:=0;
  while (c>0) do begin
    inc(cr);
    c:=c div bb;
  end;
  if (cr>res)then res:=cr;
  inc(bb);
  writeln(res);
end.