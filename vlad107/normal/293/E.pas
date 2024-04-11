{$r-,q-,s-,i-,o+}
const
  inf=1500000000;

var
  ans:int64;
  kn,x,z,i,v,kh,minv,aw,bv,n1,n2,n,maxl,maxw,kg,kg2:longint;
  rev,h1,h2,size,g,p,pred,last,g2,p2,pred2,last2,sa,aa,bb,cc,dd:array[0..500500]of longint;
  used:array[0..500500]of boolean;

  procedure adde(x,y,z:longint);
    begin
      inc(kg);g[kg]:=y;p[kg]:=z;pred[kg]:=last[x];last[x]:=kg;
    end;

  procedure adde2(x,y,z:longint);
    begin
      inc(kg2);g2[kg2]:=y;p2[kg2]:=z;pred2[kg2]:=last2[x];last2[x]:=kg2;
    end;
    
  procedure swap(var x,y:longint);
    var
      tmp:longint;
      
    begin
      tmp:=x;x:=y;y:=tmp;
    end;
    
  procedure addh(nom,size:longint);
    var
      x:longint;
    begin
      inc(kh);
      h1[kh]:=nom;
      h2[kh]:=size;
      x:=kh;
      while (x>0)and(h2[x]<h2[x shr 1])do begin
        swap(h1[x],h1[x shr 1]);
        swap(h2[x],h2[x shr 1]);
        x:=x shr 1;
      end;
    end;
    
  function poph:longint;
    var
      x,y:longint;
    begin
      poph:=h1[1];
      swap(h1[1],h1[kh]);
      swap(h2[1],h2[kh]);
      dec(kh);
      x:=1;
      while (x+x<=kh)do begin
        y:=x+x;
        if (y<kh)and(h2[y+1]<h2[y])then inc(y);
        if (h2[x]<=h2[y])then break;
        swap(h1[x],h1[y]);
        swap(h2[x],h2[y]);
        x:=y;
      end;
    end;
    
  procedure qs1(l,r:longint);
    var
      i,j,nn,xx,yy:longint;
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=aa[nn];
      yy:=bb[nn];
      while (i<=j)do begin
        while (yy>bb[i])do inc(i);
        while (yy<bb[j])do dec(j);
        if (i>j)then break;
        swap(aa[i],aa[j]);
        swap(bb[i],bb[j]);
        inc(i);dec(j);
      end;
      if (i<r)then qs1(i,r);
      if (j>l)then qs1(l,j);
    end;
    
  procedure qs2(l,r:longint);
    var
      i,j,nn,xx,yy:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=cc[nn];
      yy:=dd[nn];
      while (i<=j)do begin
        while (yy>dd[i])do inc(i);
        while (yy<dd[j])do dec(j);
        if (i>j)then break;
        swap(cc[i],cc[j]);
        swap(dd[i],dd[j]);
        inc(i);dec(j);
      end;
      if (i<r)then qs2(i,r);
      if (j>l)then qs2(l,j);
    end;

  procedure dfs1(x,px:longint);
    var
      ii:longint;
    begin
      size[x]:=1;
      inc(kn);
      ii:=last[x];
      while (ii>0)do begin
        if (g[ii]<>px)and(g[ii]<>bv)and(not used[g[ii]])then begin
          dfs1(g[ii],x);
          inc(size[x],size[g[ii]]);
        end;
        ii:=pred[ii];
      end;
    end;
    
  procedure dfs2(x,px:longint);
    var
      max,ii:longint;
    begin
      ii:=last[x];
      max:=0;
      while (ii>0)do begin
        if (g[ii]<>px)and(not used[g[ii]])then begin
          dfs2(g[ii],x);
          if (size[g[ii]]>max)then max:=size[g[ii]];
        end;
        ii:=pred[ii];
      end;
      if (kn-size[x]>max)then max:=kn-size[x];
      if (max<=minv)then begin
        minv:=max;
        v:=x;
      end;
    end;
    
  procedure dfs3(x,px,u,len,sum:longint);
    var
      ii:longint;
    begin
      adde2(u,len+1,sum+aw);
      if (len+1<=maxl)and(sum+aw<=maxw)then inc(ans);
      ii:=last[x];
      while (ii>0)do begin
        if (g[ii]<>px)and(g[ii]<>bv)and(not used[g[ii]])
          then dfs3(g[ii],x,u,len+1,sum+p[ii]);
        ii:=pred[ii];
      end;
    end;
    
  procedure adds(x:longint);
    begin
      while (x<=n)do begin
        inc(sa[x]);
        x:=x or (x-1)+1;
      end;
    end;
    
  function finds(x:longint):longint;
    var
      res:longint;
      
    begin
      res:=0;
      while (x>0)do begin
        inc(res,sa[x]);
        x:=x and (x-1);
      end;
      finds:=res;
    end;
    
    
  procedure merge(x,y:longint);
    var
      tt,jj,i,ii:longint;
    begin
      n1:=0;n2:=0;
      ii:=last2[x];
      while (ii>0)do begin
        inc(n1);
        aa[n1]:=g2[ii];
        bb[n1]:=p2[ii];
        ii:=pred2[ii];
      end;
      ii:=last2[y];
      while (ii>0)do begin
        inc(n2);
        cc[n2]:=g2[ii];
        dd[n2]:=p2[ii];
        ii:=pred2[ii];
      end;
      qs1(1,n1);
      qs2(1,n2);
      jj:=0;
      for i:=1 to n1+n2 do sa[i]:=0;
      for i:=n1 downto 1 do begin
        while (jj<n2)and(dd[jj+1]+bb[i]<=maxw)do begin
          adds(cc[jj+1]);
          inc(jj);
        end;
        tt:=maxl-aa[i];
        if (tt>n1+n2)then tt:=n1+n2;
        ans:=ans+finds(tt);
      end;
      ii:=last2[y];
      while (ii>0)do begin
        adde2(x,g2[ii],p2[ii]);
        ii:=pred2[ii];
      end;
      last2[y]:=0;
    end;

  procedure rec(x,px:longint);
    var
      sz,i,y,kc,vv,ii:longint;
    begin
      kn:=0;
      minv:=inf;
      bv:=px;
      dfs1(x,px);
      dfs2(x,px);
      vv:=v;
      ii:=last[vv];
      kc:=0;
      used[px]:=true;
      while (ii>0)do begin
        if (g[ii]<>px)and(not used[g[ii]])then begin
          rec(g[ii],vv);
          inc(kc);
        end;
        ii:=pred[ii];
      end;
      used[px]:=false;
      if (kc=0)then exit;
      bv:=px;
      kn:=0;
      dfs1(vv,0);
      kh:=0;
      ii:=last[vv];
      kg2:=0;
      for i:=1 to kc do last2[i]:=0;
      kc:=0;
      while (ii>0)do begin
        if (g[ii]<>bv)and(not used[g[ii]])then begin
          inc(kc);
          rev[g[ii]]:=kc;
          addh(kc,size[g[ii]]);
          aw:=p[ii];
          dfs3(g[ii],vv,kc,0,0);
        end;
        ii:=pred[ii];
      end;
      for i:=1 to kc-1 do begin
        x:=poph;
        y:=poph;
        merge(x,y);
        sz:=0;
        ii:=last2[x];
        while (ii>0)do begin
          inc(sz);
          ii:=pred2[ii];
        end;
        addh(x,sz);
      end;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,maxl,maxw);
  for i:=2 to n do begin
    read(x,z);
    adde(x,i,z);
    adde(i,x,z);
  end;
  ans:=0;
  fillchar(used,sizeof(used),false);
  rec(1,0);
  writeln(ans);
end.