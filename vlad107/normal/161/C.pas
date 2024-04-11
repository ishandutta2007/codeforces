uses
  math;
var
  l1,r1,l2,r2,ans:longint;
  
  procedure solve(x,l1,r1,l2,r2:longint);
    var
      cr,t:longint;
    begin
      if (l1>=l2)and(r1<=r2)then begin
        cr:=r1-l1+1;
        if (cr>ans)then ans:=cr;
        exit;
      end;
      if (l2>=l1)and(r2<=r1)then begin
        cr:=r2-l2+1;
        if (cr>ans)then ans:=cr;
        exit;
      end;
      if (x=0)then exit;
      t:=1 shl (x-1);
      if (l1<=t)and(l2<=t)and(r1>=t)and(r2>=t)then begin
        cr:=min(r1,r2)-max(l1,l2)+1;
        if (cr>ans)then ans:=cr;
      end;
      if (l1<t)and(l2<t)then solve(x-1,l1,min(t-1,r1),l2,min(r2,t-1));
      if (r1>t)and(r2>t)then solve(x-1,max(l1,t+1)-t,r1-t,max(l2,t+1)-t,r2-t);
      if (l1<t)and(r2>t)then solve(x-1,l1,min(t-1,r1),max(t+1,l2)-t,r2-t);
      if (r1>t)and(l2<t)then solve(x-1,max(l1,t+1)-t,r1-t,l2,min(r2,t-1));
    end;

begin
  read(l1,r1,l2,r2);
  ans:=0;
  solve(30,l1,r1,l2,r2);
  writeln(ans);
end.