{$r-,q-,s-,i-,o+}
var
  d,g:array[0..1111,0..1111]of longint;
  a,b:array[0..1111,0..20]of longint;
  s:array[0..1111]of string;
  kg,c,q,nn:array[0..1000500]of longint;
  m,i,j,n,ss,ff,tt,t,x,nom:longint;
begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(n,t);
  for i:=1 to n do
    for j:=1 to 2 do read(a[i][j],b[i][j]);

  readln(m);
  for i:=1 to m do begin
    readln(s[i]);
    readln(c[i]);
  end;

  for i:=1 to m do q[i]:=i;
  for i:=1 to n do nn[i]:=1;

  fillchar(d,sizeof(d),$0);
  ss:=1;
  ff:=m;
  i:=1;

  while (ss<=ff)do begin
    j:=nn[i];
    nn[i]:=3-nn[i];
    tt:=t;

    while (ss<=ff)do begin
      nom:=q[ss];
      x:=c[nom]-(a[i][j]+b[i][3-j])-d[i][nom];
      if (x<1)then x:=1;

      if (x>tt)then begin
        inc(d[i][nom],tt);
        inc(ss);
        inc(ff);
        q[ff]:=nom;
        break;
      end;
      inc(kg[i]);g[i][kg[i]]:=nom;
      dec(tt,x);
      inc(ss);
      if (tt=0)then break;
    end;
    inc(i);
    if (i>n)then i:=1;
  end;
  for i:=1 to n do begin
    write(kg[i]);
    for j:=1 to kg[i] do write(' ',s[g[i][j]]);
    writeln;
  end;
  close(output);close(input);
end.