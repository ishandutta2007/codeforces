{$r-,q-,s-,i-,o+}
var
  o,tt,res,n,i,kg,x,y,nx,mx:longint;
  last,pred,g:array[0..1111]of longint;
  procedure dfs(x,px,dx:longint);
    var
      y,ii:longint;
    begin
      if (dx>mx)then begin
        mx:=dx;nx:=x;
      end;
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)then dfs(y,x,dx+1);
        ii:=pred[ii];
      end;
    end;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(tt);
  res:=0;
  while (tt>0)do begin
    dec(tt);
    read(n);
    kg:=0;
    fillchar(pred,sizeof(pred),$0);
    fillchar(last,sizeof(last),$0);
    for i:=1 to n-1 do begin
      read(x,y);
      inc(kg);pred[kg]:=last[x];last[x]:=kg;g[kg]:=y;
      inc(kg);pred[kg]:=last[y];last[y]:=kg;g[kg]:=x;
    end;
    nx:=0;mx:=0;
    dfs(1,0,0);
    o:=nx;
    nx:=0;mx:=0;
    dfs(o,0,0);
    inc(res,mx);
  end;
  writeln(res);
  close(output);close(input);
end.