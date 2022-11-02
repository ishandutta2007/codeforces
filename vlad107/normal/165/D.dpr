{$r-,q-,s-,i-,o+}
const
  MAXN=500500;
  
var
  px,root,ii,tt,dd,tq,d1,d2,nx,ny,kt,kp,kg,n,x,y,i:longint;
  ss,dist,nom,nomb,pow,g,pred,last,st,ft,sum:array[0..MAXN]of longint;

  function next(x,px:longint):longint; 
    var
      ii:longint;
      
    begin
      ii:=last[x];
      while (ii>0)do begin
        if (g[ii]<>px)then begin
          next:=g[ii];
          exit;
        end;
        ii:=pred[ii];
      end;
      next:=-1;
    end;
    
  function findsum(x:longint):longint;
    var
      res:longint;
      
    begin
      res:=0;
      while (x>0)do begin
        inc(res,sum[x]);
        x:=x and (x-1);
      end;
      findsum:=res;
    end;
    
  procedure modify(x,val:longint);
    begin
      while (x<=MAXN)do begin
        inc(sum[x],val);
        x:=x or (x-1)+1;
      end;
    end;
    
  function find(x,y:longint):longint;
    var
      dd,tmp:longint;
      root:boolean;
      
    begin
      if (x=y)then begin
        find:=0;
        exit;
      end;
      if (x>y)then begin
        tmp:=x;x:=y;y:=tmp;
      end;
      root:=false;
      if (x=0)then begin
        x:=nomb[ss[nom[y]]];
        root:=true;
      end;
      if (root)then dd:=findsum(y)-findsum(x-1) else dd:=findsum(y)-findsum(x);
      if (dd=0)
        then find:=y-x+ord(root)
        else find:=-1;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  fillchar(pow,sizeof(pow),$0);
  kg:=0;
  fillchar(last,sizeof(last),$0);
  for i:=1 to n-1 do begin
    reaD(x,y);
    inc(pow[x]);
    inc(pow[y]);
    st[i]:=x;ft[i]:=y;
    inc(kg);
    g[kg]:=y;
    pred[kg]:=last[x];
    last[x]:=kg;
    
    inc(kg);
    g[kg]:=x;
    pred[kg]:=last[y];
    last[y]:=kg;
  end;
  x:=1;
  for i:=2 to n do if (pow[i]>pow[x])then x:=i;
  
  kt:=0;kp:=0;
  root:=x;
  ii:=last[root];
  dist[root]:=0;
  while (ii>0)do begin
	x:=g[ii];
	inc(kt);
	ss[kt]:=x;
	px:=root;
	while (x<>-1)do begin
	  //add(kt,x);
	  dist[x]:=dist[px]+1;
	  inc(kp);
	  nomb[x]:=kp;
	  nom[kp]:=kt;
	  nx:=next(x,px);
	  px:=x;
	  x:=nx;
	end;
	ii:=pred[ii];
  end;
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(tq);
    if (tq=1)then begin
      reaD(x);
      if (dist[st[x]]>dist[ft[x]])
        then modify(nomb[st[x]],-1)
        else modify(nomb[ft[x]],-1);
      continue;
    end;
    if (tq=2)then begin
      reaD(x);
      if (dist[st[x]]>dist[ft[x]])
        then modify(nomb[st[x]],+1)
        else modify(nomb[ft[x]],+1);
      continue;
    end;
    read(x,y);
    nx:=nomb[x];
    ny:=nomb[y];
    if (nom[nx]=nom[ny])then begin
      dd:=find(nx,ny);
      writeln(dd);
    end else begin
      d1:=find(0,nx);
      d2:=find(0,ny);
      if (d1<0)or(d2<0)
        then writeln(-1)
        else writeln(d1+d2);
    end;
  end;
  close(Output);close(input);
end.