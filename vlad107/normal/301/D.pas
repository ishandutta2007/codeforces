{$r-,q-,s-,i-,o+}
const
  maxn=300000;

var
  tmp,n,m,pm,i,j,ca:longint;
  rev,a,ans,l,r,nom,sa:array[0..5000500]of longint;

  procedure qs(ll,rr:longint);
    var
      nn,yy,i,j,tmp,xx:longint;
      
    begin
      i:=ll;j:=rr;
      nn:=ll+random(rr-ll+1);
      xx:=r[nn];yy:=nom[nn];
      while (i<=j)do begin
        while (xx>r[i])or(xx=r[i])and(yy>nom[i])do inc(i);
        while (xx<r[j])or(xx=r[j])and(yy<nom[j])do dec(j);
        if (i>j)then break;
        tmp:=l[i];l[i]:=l[j];l[j]:=tmp;
        tmp:=r[i];r[i]:=r[j];r[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<rr)then qs(i,rr);
      if (j>ll)then qs(ll,j);
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,m);
  pm:=m;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do rev[a[i]]:=i;
  for i:=1 to m do begin
    read(l[i],r[i]);
    nom[i]:=i;
  end;
  for i:=1 to maxn do 
    if (rev[i]<>0)then 
      for j:=1 to maxn div i do 
        if (rev[i*j]<>0)then begin
          inc(m);
          l[m]:=rev[i];
          r[m]:=rev[i*j];
          if (r[m]<l[m])then begin
            tmp:=l[m];l[m]:=r[m];r[m]:=tmp;
          end;
          nom[m]:=0;
        end;
  qs(1,m);
  for i:=1 to m do 
    if (nom[i]=0)then begin
      j:=l[i];
      while (j<=maxn)do begin
        inc(sa[j]);
        j:=j or (j-1)+1;
      end;
    end else begin
      j:=l[i]-1;
      ca:=0;
      while (j>0)do begin
        dec(ca,sa[j]);
        j:=j and (j-1);
      end;
      j:=maxn;
      while (j>0)do begin
        inc(ca,sa[j]);
        j:=j and (j-1);
      end;
      ans[nom[i]]:=ca;
    end;
  for i:=1 to pm do writeln(ans[i]);
end.