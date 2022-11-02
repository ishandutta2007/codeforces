var
  ok:boolean;
  q,t,tmp,s,p:ansistring;
  lt,i,n,res,tt:longint;
  f,g,z,zz:array[0..500500]of longint;

  procedure kmp;
    var
      tq,i:longint;

    begin
      tq:=0;
      for i:=2 to lt do begin
        while (tq>0)and(t[tq+1]<>t[i])do tq:=zz[tq];
        if (t[tq+1]=t[i])then inc(tq);
        zz[i]:=tq;
      end;
      tq:=0;
      t:=t+'!';
      for i:=1 to n do begin
        while (tq>0)and(t[tq+1]<>s[i])do tq:=zz[tq];
        if (t[tq+1]=s[i])then inc(tq);
        z[i]:=tq;
      end;
      delete(t,1,1);
    end;

begin
  readln(s);
  p:='';
  n:=length(s);
  for i:=length(s)downto 1 do p:=p+s[i];
  res:=0;
  readln(tt);
  g[0]:=0;
  f[0]:=0;
  while (tt>0)do begin
    dec(tt);
    readln(t);
    lt:=length(t);
    if (lt<2)then continue;
    q:='';
    for i:=lt downto 1 do q:=q+t[i];

    kmp;
    for i:=1 to n do begin
      f[i]:=z[i];
      if (f[i-1]>f[i])then f[i]:=f[i-1];
    end;
    tmp:=s;s:=p;p:=tmp;

    t:=q;
    kmp;
    tmp:=s;s:=p;p:=tmp;
    for i:=1 to n do begin
      g[i]:=z[i];
      if (g[i-1]>g[i])then g[i]:=g[i-1];
    end;
    ok:=false;
    for i:=1 to n do
      if (f[i]<>0)and(g[n-i]<>0)and(f[i]+g[n-i]>=lt)then begin
        ok:=true;
        break;
      end;
    if (ok)then inc(res);
  end;
  writeln(res);
end.