{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
  infinf:int64=1000000000000000000;

var
  h,ss,r,o,s,p,nom:array[0..500500]of longint;
  t:array[0..500500]of int64;
  ans,time:array[0..500500]of int64;
  kh,fq,ll,rr,mm,kr,ko,i,n:longint;
  tt:int64;
  
  procedure down(x:longint);
    var
      tmp:longint;
      
    begin
      while (x>1)and(p[h[x shr 1]]<p[h[x]])do begin
        tmp:=h[x];h[x]:=h[x shr 1];h[x shr 1]:=tmp;
        x:=x shr 1;
      end;
    end;
    
  procedure up(x:longint);
    var
      y,tmp:longint;
      
    begin
      while (x+x<=kh)do begin
        y:=x+x;
        if (y<kh)and(p[h[y+1]]>p[h[y]])then inc(y);
        if (p[h[x]]>p[h[y]])then break;
        tmp:=h[x];h[x]:=h[y];h[y]:=tmp;
        x:=y;
      end;
    end;
    
  
  
  procedure qsr(ll,rr:longint);
    var
      i,j,tmp,x:longint;
      
    begin
      i:=ll;j:=rr;
      x:=r[i+random(j-i+1)];
      while (i<=j)do begin
        while (x>r[i])do inc(i);
        while (x<r[j])do dec(j);
        if (i>j)then break;
        tmp:=r[i];r[i]:=r[j];r[j]:=tmp;
        inc(I);dec(j);
      end;
      if (i<rr)then qsr(i,rr);
      if (j>ll)then qsr(ll,j);
    end;
    
  procedure qst(ll,rr:longint);
    var
      i,j,tmp,xx:longint;
      
    begin
      i:=ll;j:=rr;
      xx:=t[i+random(j-i+1)];
      while (i<=j)do begin
        while (xx>t[i])do inc(i);
        while (xx<t[j])do dec(j);
        if (i>j)then break;
        tmp:=t[i];t[i]:=t[j];t[j]:=tmp;
        tmp:=p[i];p[i]:=p[j];p[j]:=tmp;
        tmp:=s[i];s[i]:=s[j];s[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<rr)then qst(i,rr);
      if (j>ll)then qst(ll,j);
    end;
    
  procedure solve;
    var
      tq,dt:int64;
      i,x:longint;
      
    begin
      t[n+1]:=infinf;
      for i:=1 to n do ss[i]:=s[i];
      kh:=0;
      for i:=1 to n do begin
        inc(kh);
        h[kh]:=i;
        down(kh);
        dt:=t[i+1]-t[i];
        tq:=t[i];
        while (dt>0)and(kh>0)do begin
          x:=h[1];
          if (dt>=ss[x])then begin
            time[x]:=tq+ss[x];
            tq:=tq+ss[x];
            h[1]:=h[kh];
            dec(kh);
            up(1);
            dt:=dt-ss[x];
          end else begin
            ss[x]:=ss[x]-dt;
            break;
          end;
        end;
      end;
    end;

begin
  randseed:=54367;
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(t[i],s[i],p[i]);
  read(tt);
  for i:=1 to n do nom[i]:=i;
  qst(1,n);
  
  kr:=0;
  for i:=1 to n do 
    if (p[i]<0)then fq:=i else begin
      inc(kr);
      r[kr]:=p[i];
    end;
  qsr(1,kr);
  ko:=0;
  if (r[1]>1)then begin inc(ko);o[ko]:=1; end;
  for i:=1 to kr do 
    if (r[i]<>inf)and((i=kr)or(r[i]+1<>r[i+1]))then begin
      inc(ko);o[ko]:=r[i]+1;
    end;
  ll:=1;rr:=ko;
  while (ll<rr-1)do begin
    mm:=(ll+rr)shr 1;
    p[fq]:=o[mm];
    solve;
    if (tt<time[fq])
      then ll:=mm
      else rr:=mm;
  end;
  p[fq]:=o[ll];
  solve;
  if (time[fq]<>tt)then begin
    p[fq]:=o[rr];
    solve;
  end;
  for i:=1 to n do ans[nom[i]]:=time[i];
  writeln(p[fq]);
  for i:=1 to n do write(ans[i],' ');
end.