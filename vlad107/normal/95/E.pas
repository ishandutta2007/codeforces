{$r-,q-,s-,i-,o+}
{$M 2000000}
const
  inf=1000000000;
  maxn=77777;
var
  res,j,q,mm,tk,kst1,kst2,n,m,i,x,y,kg:longint;
  kol,last,pred,g:array[0..200500]of longint;
  st1,t,fst1,fst2,ast1,ast2,mst1,mst2,f:array[0..200500]of longint;
  used:array[0..100500]of boolean;
  procedure dfs(x:longint);
    var
      ii:longint;
    begin
      inc(tk);
      used[x]:=true;
      ii:=last[x];
      while (ii>0)do begin
        if (not used[g[ii]])then dfs(g[ii]);
        ii:=pred[ii];
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m);
  for i:=1 to m do begin
    read(x,y);
    inc(kg);
    g[kg]:=y;
    pred[kg]:=last[x];
    last[x]:=kg;
    
    inc(kg);
    g[kg]:=x;
    pred[kg]:=last[y];
    last[y]:=kg;
  end;
  fillchar(used,sizeof(used),false);
  for i:=1 to n do 
    if (not used[i])then begin
      tk:=0;
      dfs(i);
      inc(kol[tk]);
    end;
  for i:=1 to maxn do f[i]:=inf;
  f[0]:=0;
  mst1[0]:=inf;mst2[0]:=inf;
  ast1[0]:=0;ast2[0]:=0;
  kst1:=0;kst2:=0;
  for i:=1 to maxn do begin
    if (kol[i]=0)then continue;
    tk:=kol[i];
    for j:=0 to i-1 do begin
      q:=j;
      t[0]:=0;
      while (q<=maxn)do begin
        inc(t[0]);
        t[t[0]]:=f[q];
        inc(q,i);
      end;
      kst1:=0;kst2:=0;
      ast1[0]:=0;ast2[0]:=0;
      for q:=1 to t[0] do begin
        if (kst1>0)then inc(ast1[kst1]);
        if (kst2>0)then inc(ast2[kst2]);
        if (kst1+kst2=0)then mm:=inf else
        if (kst2>0)and((kst1=0)or(mst2[kst2]+ast2[kst2]<mst1[kst1]+ast1[kst1]))
          then mm:=mst2[kst2]+ast2[kst2]
          else mm:=mst1[kst1]+ast1[kst1];
        if (mm<t[q])then f[(q-1)*i+j]:=mm;
        if (t[q]<>inf)then begin
          inc(kst1);
          st1[kst1]:=t[q];
          if (t[q]<mst1[kst1-1]+ast1[kst1-1])then begin
            mst1[kst1]:=t[q];
            ast1[kst1]:=0;
          end else begin
            mst1[kst1]:=mst1[kst1-1];
            ast1[kst1]:=ast1[kst1-1];
          end;
          fst1[kst1]:=ast1[kst1];
        end;
        if (q>tk)and(t[q-tk]<>inf)then begin
          if (kst2=0)then begin
            while (kst1>0)do begin
              mm:=st1[kst1]+ast1[kst1]-fst1[kst1];
              dec(kst1);
              inc(ast1[kst1],ast1[kst1+1]-fst1[kst1+1]);
              inc(kst2);
              if (mm>mst2[kst2-1]+ast2[kst2-1])then begin
                mst2[kst2]:=mst2[kst2-1];
                ast2[kst2]:=ast2[kst2-1];
              end else begin
                mst2[kst2]:=mm;
                ast2[kst2]:=0;
              end;
              fst2[kst2]:=ast2[kst2];
            end;
          end;
          dec(kst2);
          inc(ast2[kst2],ast2[kst2+1]-fst2[kst2+1]);
        end;
      end;
    end;
  end;
  res:=inf;
  for i:=1 to maxn do begin
    x:=i;
    while (x>0)do begin
      if (x mod 10<>7)and(x mod 10<>4)then break;
      x:=x div 10;
    end;
    if (x=0)and(f[i]<res)then res:=f[i];
  end;
  if (res=inf)then res:=0;
  writeln(res-1);
  close(output);close(input);
end.