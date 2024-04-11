{$r-,q-,s-,i-,o+}
const
  inf=1000000001;

var
  qq,qt,lt,kg,ii,kh,ans,n,m,ss,i,x,y,z:longint;
  p,revn,pred,last,g,h,dst:array[0..500500]of longint;
  used:array[0..500500]of boolean;
  
  procedure swap(x,y:longint);
    var
      tmp:longint;
      
    begin
      tmp:=h[x];h[x]:=h[y];h[y]:=tmp;
      revn[h[x]]:=x;
      revn[h[y]]:=y;
    end;
    
  procedure up(x:longint);
    var
      y:longint;
      
    begin
      while (x+x<=kh)do begin
        y:=x+x;
        if (y+1<=kh)and(dst[h[y]]>dst[h[y+1]])then inc(y);
        if (dst[h[x]]<=dst[h[y]])then break;
        swap(x,y);
        x:=y;
      end;
    end;
    
  procedure down(x:longint);
    begin
      while (x>1)and(dst[h[x]]<dst[h[x shr 1]])do begin
        swap(x,x shr 1);
        x:=x shr 1;
      end;
    end;

begin
  read(n,m,ss);
  fillchar(pred,sizeof(pred),$0);
  fillchar(last,sizeof(last),$0);
  kh:=0;kg:=0;
  for i:=1 to m do begin
    read(x,y,z);
    inc(kg);g[kg]:=y;p[kg]:=z;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;p[kg]:=z;pred[kg]:=last[y];last[y]:=kg;
  end;
  read(lt);
  
  for i:=1 to n do begin
    dst[i]:=inf;
    inc(kh);
    h[kh]:=i;
    revn[i]:=kh;
    down(kh);
  end;
  dst[ss]:=0;
  down(revn[ss]);
  fillchar(used,sizeof(used),false);
  for i:=1 to n do begin
    x:=h[1];
    if (dst[x]=inf)then break;
    swap(1,kh);
    dec(kh);
    up(1);
    used[x]:=true;
    ii:=last[x];
    while (ii>0)do begin
      y:=g[ii];
      if (not used[y])and(dst[x]+p[ii]<dst[y])then begin
        dst[y]:=dst[x]+p[ii];
        down(revn[y]);
      end;
      ii:=pred[ii];
    end;
  end;
  ans:=0;
  qt:=0;
  for i:=1 to n do begin
    if (dst[i]>=lt)then continue;
    ii:=last[i];
    while (ii>0)do begin
      if (dst[i]+p[ii]>lt)then begin
        x:=g[ii];
        qq:=p[ii]-(lt-dst[i]);
        if (lt<dst[x]+qq)then inc(ans);
        if (lt=dst[x]+qq)then inc(qt);
      end;
      ii:=pred[ii];
    end;
  end;
  ans:=ans+qt div 2;
  for i:=1 to n do 
    if (dst[i]=lt)then inc(ans);
  writeln(ans);
end.