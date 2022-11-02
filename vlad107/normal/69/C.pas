{$r-,q-,s-,i-,o+}
var
  qq,kt,cr,k,n,m,tt,i,kss,j,x,y,z:longint;
  ch:char;
  g,p,kr:array[0..1111,0..1111]of longint;
  s:ansistring;
  ok:boolean;
  qt,kg:array[0..1111]of longint;
  st,ss:array[0..1111]of ansistring;
  function fnom(s:ansistring):longint;
    var
      i:longint;
    begin
      i:=1;
      while (i<=kss)and(s<>ss[i])do inc(i);
      if (i>kss)then begin
        inc(kss);
        ss[kss]:=s;
        fnom:=kss;
      end else fnom:=i;
    end;
begin
  readln(k,n,m,tt);
  kss:=0;
  for i:=1 to n do begin
    readln(s);
    x:=fnom(s);
  end;
  for i:=1 to m do begin
    readln(s);
    x:=fnom(copy(s,1,pos(':',s)-1));
    delete(s,1,pos(' ',s));
    kg[x]:=0;
    j:=1;
    s:=s+', ';
    while (s<>'')do begin
      y:=fnom(copy(s,1,pos(' ',s)-1));
      delete(s,1,pos(' ',s));
      val(copy(s,1,pos(',',s)-1),z);
      delete(s,1,pos(' ',s));
      inc(kg[x]);
      g[x][kg[x]]:=y;
      p[x][kg[x]]:=z;
    end;
  end;
  fillchar(kr,sizeof(kr),$0);
  while (tt>0)do begin
    dec(tt);
    read(ch);
    x:=0;
    while (ch>='0')and(ch<='9')do begin
      x:=x*10+ord(ch)-48;
      read(ch);
    end;
    readln(s);
    y:=fnom(s);
    inc(kr[x][y]);
    for i:=n+1 to n+m do begin
      ok:=true;
      for j:=1 to kg[i]do
        if (kr[x][g[i][j]]<p[i][j])then begin
          ok:=false;
          break;
        end;
      if (ok)then begin
        for j:=1 to kg[i]do dec(kr[x][g[i][j]],p[i][j]);
        inc(kr[x][i]);
        break;
      end;
    end;
  end;
  for i:=1 to k do begin
    cr:=0;
    for j:=1 to n+m do
      if (kr[i][j]>0)then inc(cr);
    writeln(cr);
    kt:=0;
    for j:=1 to n+m do
      if (kr[i][j]>0)then begin
        inc(kt);
        st[kt]:=ss[j];
        qt[kt]:=kr[i][j];
      end;
    for qq:=1 to kt-1 do 
      for j:=1 to kt-1 do 
        if (st[j]>st[j+1])then begin
          s:=st[j];st[j]:=st[j+1];st[j+1]:=s;
          x:=qt[j];qt[j]:=qt[j+1];qt[j+1]:=x;
        end;
    for j:=1 to kt do writeln(st[j],' ',qt[j]);
  end;
end.