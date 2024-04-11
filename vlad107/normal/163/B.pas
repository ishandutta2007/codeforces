const
  eps=1e-9;

var
  nom,m,v:array[0..500500]of longint;
  i,it,qh,n,k,h:longint;
  lt,rt,t:extended;

  procedure qs(l,r:longint);
    var
      yy,nn,i,j,xx,tmp:longint;

    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=m[nn];
      yy:=v[nn];
      while (i<=j)do begin
        while (xx>m[i])or(xx=m[i])and(yy>v[i])do inc(i);
        while (xx<m[j])or(xx=m[j])and(yy<v[j])do dec(j);
        if (i>j)then break;
        tmp:=m[i];m[i]:=m[j];m[j]:=tmp;
        tmp:=v[i];v[i]:=v[j];v[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  read(n,k,h);
  for i:=1 to n do read(m[i]);
  for i:=1 to n do read(v[i]);
  for i:=1 to n do nom[i]:=i;
  qs(1,n);
  lt:=0;rt:=1e9;
  for it:=1 to 200 do begin
    t:=(lt+rt)/2;
    qh:=h;
    for i:=1 to n do
      if (qh/v[i]<t+eps)then inc(qh,h);
    if (qh div h>k)
      then rt:=t
      else lt:=t;
  end;
  t:=rt;
  qh:=h;
  for i:=1 to n do
    if (qh/v[i]<t+eps)then begin
      write(nom[i],' ');
      inc(qh,h);
      if (qh div h=k+1)then break;
    end;
  writeln;
end.