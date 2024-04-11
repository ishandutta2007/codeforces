{$r-,q-,s-,i-,o+}
const 
  base=500;
var
  rta:array[0..200500]of int64;
  a,nomt,nom,l,r,lx:array[0..200500]of longint;
  ka:array[0..1005000]of longint;
  ll,rr,n,t,i:longint;
  res:int64;
  procedure qs(la,ra:longint);
    var
      yy,xx,tmp,i,j,nn:longint;
    begin
      i:=la;j:=ra;
      nn:=la+random(ra-la+1);
      xx:=lx[nn];
      yy:=r[nn];
      while (i<=j)do begin
        while (xx>lx[i])or(xx=lx[i])and(yy>r[i])do inc(i);
        while (xx<lx[j])or(xx=lx[j])and(yy<r[j])do dec(j);
        if (i>j)then break;
        tmp:=l[i];l[i]:=l[j];l[j]:=tmp;
        tmp:=r[i];r[i]:=r[j];r[j]:=tmp;
        tmp:=lx[i];lx[i]:=lx[j];lx[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<ra)then qs(i,ra);
      if (j>la)then qs(la,j);
    end;

begin
  randomize;
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,t);
  for i:=1 to n do read(a[i]);
  nomt[0]:=0;
  for i:=1 to n do begin
    nomt[i]:=nomt[i-1];
    if (i mod base=1)then inc(nomt[i]);
  end;
  for i:=1 to t do begin
    read(l[i],r[i]);
    lx[i]:=nomt[l[i]];
    nom[i]:=i;
  end;
  qs(1,t);
  fillchar(ka,sizeof(ka),$0);
  ll:=1;rr:=1;
  res:=a[1];
  ka[a[1]]:=1;
  for i:=1 to t do begin
    while (ll<>l[i])do 
      if (ll<l[i])then begin
        res:=res-int64(2*ka[a[ll]]-1)*a[ll];
        dec(ka[a[ll]]);
        inc(ll);
      end else begin
        dec(ll);
        inc(ka[a[ll]]);
        res:=res+int64(2*ka[a[ll]]-1)*a[ll];
      end;
    while (rr<>r[i])do 
      if (rr>r[i])then begin
        res:=res-int64(2*ka[a[rr]]-1)*a[rr];
        dec(ka[a[rr]]);
        dec(rr);
      end else begin
        inc(rr);
        inc(ka[a[rr]]);
        res:=res+int64(2*ka[a[rr]]-1)*a[rr];
      end;
    rta[nom[i]]:=res;
  end;
  for i:=1 to t do writeln(rta[i]);
  close(output);close(input);
end.