var
  ans2,cr1,cr2,x,y,n,m,kg,i,ans:longint;
  t,g,pred,last:array[0..500500]of longint;

  procedure dfs(x:longint);
    var
      ii,y:longint;
      
    begin
      inc(cr2);
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (t[y]=-1)then begin
          t[y]:=3-t[x];
          dfs(y);
        end;
        if (t[y]<>3-t[x])then inc(cr1);
        ii:=pred[ii];
      end;
    end;

begin
  read(n,m);
  kg:=0;
  fillchar(last,sizeof(last),$0);
  for i:=1 to m do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  fillchar(t,sizeof(t),$FF);
  ans:=0;
  for i:=1 to n do 
    if (t[i]=-1)then begin
      cr1:=0;cr2:=0;
      t[i]:=1;
      dfs(i);
      if (cr1>0)then inc(ans);
      if (cr1=0)and(cr2 and 1=1)then inc(ans2);
    end;
  writeln(ans+(ans2 and 1));
end.