{$r+,q+,s+,i+,o-}
{$ASSERTIONS ON}
const
  inf=1000000000;
  maxn=500500;
  maxq=10000000;

var
  prn,sa,ca,nom,ta,dst,prx,g,pred,last,rev,p,cp,mp:array[0..maxn]of longint; 
  q:array[0..maxq]of longint;
  inq:array[0..maxn]of boolean;
  cost,newcost,kg,ii,ss,ff,tmp,n,k,i,j:longint;
  found:boolean;

  procedure myassert(t:boolean);
    begin
      if (not t)then begin
        writeln(0);
        halt(0);
      end;
    end;

  procedure add(x,y,pt,ct:longint);
    begin
      inc(kg);
      myassert(kg<=maxn);
      g[kg]:=y;p[kg]:=0;mp[kg]:=pt;cp[kg]:=ct;pred[kg]:=last[x];last[x]:=kg;rev[kg]:=kg+1;
      inc(kg);
      myassert(kg<=maxn);
      g[kg]:=x;p[kg]:=0;mp[kg]:=0;cp[kg]:=-ct;pred[kg]:=last[y];last[y]:=kg;rev[kg]:=kg-1;
    end;
    
    
  function way:boolean;
    var
      i,qb,qe,x,y,z,ii:longint;
      
    begin
      for i:=ss to ff do dst[i]:=-inf;
      for i:=ss to ff do prx[i]:=-1;
      for i:=ss to ff do inq[i]:=false;
      dst[ss]:=0;
      qb:=0;qe:=1;
      q[1]:=ss;
      inq[ss]:=true;
      while (qb<qe)do begin
        inc(qb);
        x:=q[qb];
        inq[x]:=false;
        if (x=ff)then continue;
        ii:=last[x];
        while (ii>0)do begin
          y:=g[ii];
          if (p[ii]<mp[ii])and(dst[x]+cp[ii]>dst[y])then begin
            dst[y]:=dst[x]+cp[ii];
            prx[y]:=x;
            prn[y]:=ii;
            if (inq[y])then continue;
            inq[y]:=true;
            inc(qe);
            myassert(qe<=maxq);
            q[qe]:=y;
          end;
          ii:=pred[ii];
        end;
      end;
      if (dst[ff]=-inf)then begin
        way:=false;
        exit;
      end;
      newcost:=cost;
      x:=ff;
      while (x>0)do begin
        z:=prn[x];
        myassert(z>0);
        inc(newcost,cp[z]);
        x:=prx[x];
      end;
      if (newcost<cost)then begin
        way:=false;
        exit;
      end;
      way:=true;
      x:=ff;
      while (x>0)do begin
        y:=prx[x];
        z:=prn[x];
        myassert(z>0);
        inc(p[z]);
        dec(p[rev[z]]);
        x:=y;
      end;
    end;

begin
  
  {assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  read(n,k);
  myassert(n<=1000);
  myassert(k<=50);
  for i:=1 to n do begin
    read(sa[i],ta[i],ca[i]);
    nom[i]:=i;
  end;
  kg:=0;
  fillchar(pred,sizeof(pred),$0);
  fillchar(last,sizeof(last),$0);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do
      if (sa[j]>sa[j+1])then begin
        tmp:=sa[j];sa[j]:=sa[j+1];sa[j+1]:=tmp;
        tmp:=ta[j];ta[j]:=ta[j+1];ta[j+1]:=tmp;
        tmp:=ca[j];ca[j]:=ca[j+1];ca[j+1]:=tmp;
        tmp:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp;
      end;
  ss:=0;ff:=n+n+1;
  myassert(ff<=maxn);
  for i:=1 to n do add(nom[i],nom[i]+n,1,ca[i]);
  for i:=1 to n do begin
    if (i<n)
      then add(nom[i],nom[i+1],inf,0)
      else add(nom[i],ff,inf,0);
    found:=false;
    for j:=i+1 to n do 
      if (sa[i]+ta[i]-1<sa[j])then begin
        add(nom[i]+n,nom[j],1,0);
        found:=true;
        break;
      end;
    if (not found)then add(nom[i]+n,ff,1,0);
  end;
  add(ss,nom[1],k,0);
  cost:=0;
  while (way)do;
  for i:=1 to n do begin
    ii:=last[i];
    while (ii>0)do begin
      if (g[ii]=i+n)then begin
        write(p[ii],' ');
        break;
      end;
      ii:=pred[ii];
    end;
  end;
  close(output);close(input);
end.