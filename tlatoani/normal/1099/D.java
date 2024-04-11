import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class SumInTheTree {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        int n = in.nextInt();
        Node[] nodes = new Node[n];
        nodes[0] = new Node(0, null);
        for (int i = 1; i < n; i++) {
            nodes[i] = new Node(i, nodes[in.nextInt() - 1]);
            nodes[i].parent.children.add(nodes[i]);
        }
        for (int i = 0; i < n; i++) {
            nodes[i].s = in.nextLong();
        }
        Stack<Node> stack = new Stack<>();
        long sum = 0;
        stack.push(nodes[0]);
        while (!stack.isEmpty()) {
            Node node = stack.pop();
            if (node.s == -1) {
                if (node.children.isEmpty()) {
                    node.a = 0;
                    node.s = node.parent.s;
                } else {
                    long minSOfChildren = Long.MAX_VALUE;
                    for (Node child : node.children) {
                        minSOfChildren = Math.min(minSOfChildren, child.s);
                    }
                    node.a = minSOfChildren - node.parent.s;
                    node.s = minSOfChildren;
                }
            } else if (node.parent == null) {
                node.a = node.s;
            } else {
                node.a = node.s - node.parent.s;
            }
            if (node.a < 0) {
                out.println("-1");
                return;
            }
            sum += node.a;
            //out.println("for node " + (node.ix + 1) + ", a = " + node.a);
            for (Node child : node.children) {
                stack.push(child);
            }
        }
        out.println(sum);
    }

    static class Node {
        final int ix;
        final Node parent;
        final List<Node> children = new ArrayList<>();
        long a = -1;
        long s = -1;

        Node(int ix, Node parent) {
            this.ix = ix;
            this.parent = parent;
        }
    }
}