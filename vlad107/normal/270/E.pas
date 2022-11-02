var
  ans:array[0..500500]of longint;
  qb,qe,ii,kg,i,n,m,x,y,z:longint;
  q,cnt,g,p,sr,pred,last,nom:array[0..500500]of longint;
  used:array[0..500500]of boolean;
  
begin
  read(n,m);
  for i:=1 to m do begin
    read(x,y,z);
    inc(cnt[x],z);
    inc(cnt[y],z);
    inc(kg);
    g[kg]:=y;
    p[kg]:=z;
    sr[kg]:=0;
    nom[kg]:=i;
    pred[kg]:=last[x];
    last[x]:=kg;
    
    inc(kg);
    g[kg]:=x;
    p[kg]:=z;
    sr[kg]:=1;
    nom[kg]:=i;
    pred[kg]:=last[y];
    last[y]:=kg;
  end;
  for i:=1 to n do cnt[i]:=cnt[i] shr 1;
  qb:=0;qe:=1;
  q[1]:=1;
  fillchar(used,sizeof(used),false);
  while (qb<qe)do begin
    inc(qb);
    x:=q[qb];
    if (x=n)then continue;
    ii:=last[x];
    while (ii>0)do begin
      y:=g[ii];
      if (used[nom[ii]])then begin
        ii:=pred[ii];
        continue;
      end;
      used[nom[ii]]:=true;
      ans[nom[ii]]:=sr[ii];
      dec(cnt[y],p[ii]);
      if (cnt[y]=0)then begin
        inc(qe);
        q[qe]:=y;
      end;
      ii:=pred[ii];
    end;
  end;
  for i:=1 to m do writeln(ans[i]);
end.