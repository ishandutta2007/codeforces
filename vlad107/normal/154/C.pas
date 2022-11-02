
const
  base=10000007;
  MAXM=2005000;
  
var
  res,hh:qword;
  x,y,kw,kg,kg1,kg2,n,m,i,ii:longint;
  p1,p2,g,pred,pred1,pred2,last,w:array[0..MAXM]of longint;
  g1,g2:array[0..MAXM]of qword;
  last1,last2:array[0..base+5]of longint;

  procedure qs(l,r:longint);
    var
      xx,tmp,i,j,nn:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=w[nn];
      while (i<=j)do begin
        while (xx>w[i])do inc(i);
        while (xx<w[j])do dec(j);
        if (i>j)then break;
        tmp:=w[i];w[i]:=w[j];w[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

  procedure add1(hh:qword);
    var
      ii,x:longint;
      y:qword;
      
    begin
      x:=hh mod base;
      ii:=last1[x];
      while (ii>0)do begin
        y:=g1[ii];
        if (y=hh)then begin
          res:=res+p1[ii];
          inc(p1[ii]);
          exit;
        end;
        ii:=pred1[ii];
      end;
      inc(kg1);
      g1[kg1]:=hh;
      p1[kg1]:=1;
      pred1[kg1]:=last1[x];
      last1[x]:=kg1;
    end;
    
  procedure add2(hh:qword);
    var
      ii,x:longint;
      y:qword;
      
    begin
      x:=hh mod base;
      ii:=last2[x];
      while (ii>0)do begin
        y:=g2[ii];
        if (y=hh)then begin
          res:=res+p2[ii];
          inc(p2[ii]);
          exit;
        end;
        ii:=pred2[ii];
      end;
      inc(kg2);
      g2[kg2]:=hh;
      p2[kg2]:=1;
      pred2[kg2]:=last2[x];
      last2[x]:=kg2;
    end;


begin
  randomize;
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m);
  kg:=0;
  for i:=1 to m do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  kg1:=0;kg2:=0;
  for i:=1 to n do begin
    kw:=0;
    ii:=last[i];
    while (ii>0)do begin
      inc(kw);
      w[kw]:=g[ii];
      ii:=pred[ii];
    end;
    qs(1,kw);
    hh:=0;
    for ii:=1 to kw do hh:=hh*1000003+w[ii];
    add1(hh);
    inc(kw);
    w[kw]:=i;
    qs(1,kw);
    hh:=0;
    for ii:=1 to kw do hh:=hh*1000003+w[ii];
    add2(hh);
  end;  
  writeln(Res);
  close(output);close(input);
end.