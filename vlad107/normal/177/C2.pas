{$r-,q-,s-,i-,o+}
var
  kg,kg2,ii,qb,qe,n,m,x,y,i,j,km,qqq,ans:longint;
  used,last,pred,last2,pred2,g,g2:array[0..500500]of longint;
  dislike:boolean;
  q:array[0..500500]of longint;

begin
  read(n,m);
  kg:=0;kg2:=0;
  fillchar(last,sizeof(last),$0);
  fillchar(last2,sizeof(last2),$0);
  for i:=1 to m do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  read(km);
  for i:=1 to km do begin
    read(x,y);
    inc(kg2);g2[kg2]:=y;pred2[kg2]:=last2[x];last2[x]:=kg2;
    inc(kg2);g2[kg2]:=x;pred2[kg2]:=last2[y];last2[y]:=kg2;
  end;
  fillchar(used,sizeof(used),$0);
  qqq:=0;
  ans:=0;
  for i:=1 to n do 
    if (used[i]=0)then begin
      qb:=0;qe:=1;
      q[1]:=i;
      inc(qqq);
      used[i]:=qqq;
      while (qb<qe)do begin
        inc(qb);
        x:=q[qb];
        ii:=last[x];
        while (ii>0)do begin
          if (used[g[ii]]=0)then begin
            used[g[ii]]:=qqq;
            inc(qe);
            q[qe]:=g[ii];
          end;
          ii:=pred[ii];
        end;
      end;
      dislike:=false;
      for j:=1 to qe do begin
        ii:=last2[q[j]];
        while (ii>0)do begin
          if (used[g2[ii]]=qqq)then begin
            dislike:=true;break;
          end;
          ii:=pred2[ii];
        end;
        if (dislike)then break;
      end;
      if (not dislike)and(qe>ans)then ans:=qe;
    end;
  writeln(ans);
end.