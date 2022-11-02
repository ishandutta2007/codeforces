{$r-,q-,s-,i-,o+}
const
  maxx=1111;

var
  ii,qb,qe,kg,x,y,n,i,mx,my,ans:longint;
  used:array[0..500500]of boolean;
  deg,q,g,pred,last:array[0..500500]of longint;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do begin
    read(x,y);
    inc(kg);g[kg]:=y+maxx;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y+maxx];last[y+maxx]:=kg;
    inc(deg[x]);inc(deg[y+maxx]);
  end;
  fillchar(used,sizeof(used),false);
  ans:=0;
  for i:=1 to maxx+maxx do 
    if (not used[i])and(deg[i]<>0)then begin
      inc(ans);
      qb:=0;qe:=1;
      q[1]:=i;
      used[i]:=true;
      while (qb<=qe)do begin
        inc(qb);
        x:=q[qb];
        ii:=last[x];
        while (ii>0)do begin
          y:=g[ii];
          if (not used[y])then begin
            used[y]:=true;
            inc(qe);
            q[qe]:=y;
          end;
          ii:=pred[ii];
        end;
      end;
    end;
  writeln(ans-1);
  close(output);close(input);
end.