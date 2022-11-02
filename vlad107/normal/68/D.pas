{$r-,q-,s-,i-,o+}
const
  bhash=10000019;
var
  v,e,tx,txx,txx1,max,i,kg,x,h,tt:longint;
  pred,g,kol:array[0..5005000]of longint;
  last:array[0..bhash+10]of longint;
  ch:char;
  p,res:extended;
  procedure modify(x,k:longint);
    var
      ii,y:longint;
    begin
      y:=x mod bhash;
      ii:=last[y];
      while (ii>0)do begin
        if (g[ii]=x)then begin
          inc(kol[ii],k);
          exit;
        end;
        ii:=pred[ii];
      end;
      inc(kg);
      g[kg]:=x;
      kol[kg]:=k;
      pred[kg]:=last[y];
      last[y]:=kg;
    end;
  function findsum(x:longint):longint;
    var
      y,ii:longint;
    begin
      y:=x mod bhash;
      ii:=last[y];
      while (ii>0)do begin
        if (g[ii]=x)then begin
          findsum:=kol[ii];
          exit;
        end;
        ii:=pred[ii];
      end;
      findsum:=0;
    end;
begin
  readln(h,tt);
  while (tt>0)do begin
    dec(tt);
    read(ch);
    if (ch='a')then begin
      read(ch,ch);
      readln(v,e);
      while (v>0)do begin
        modify(v,e);
        v:=v shr 1;
      end;
    end else begin
      readln;
      x:=1;
      res:=0;
      p:=1;
      max:=0;
      for i:=1 to h+1 do begin
        tx:=findsum(x);
        txx:=findsum(x+x);
        txx1:=findsum(x+x+1);
        if (max>tx-txx)and(max>tx-txx1)then begin
          res:=res+p*max;
          break;
        end;
        if (i<>h+1)then p:=p*0.5;
        if (txx>txx1)
          then begin
            res:=res+p*(tx-txx1);
            if (tx-txx>max)then max:=tx-txx;
            x:=x+x;
          end else begin
            res:=res+p*(tx-txx);
            if (tx-txx1>max)then max:=tx-txx1;
            x:=x+x+1;
          end;
      end;
      writeln(res:0:10);
    end;
  end;
end.